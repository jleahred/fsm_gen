# FSM generator

## Installation

```bash
cargo install -f fsm_gen
```

You can download from repository and build and install as usual

```bash
cargo build --release
cargo install --path . -f
```


## TODO


- revisit dot
- generate mermaid
- check README.md

- Error transition is special
- Inprove exceptions control
- web ui for templates
- read template from file

- Complete the cpp example and update on README.md
- Check fsm format
  - detect duplicated states
  - detect duplicated inputs and guards
- output with signals

- Add new templates

## Versions

### 0.8
- New cpp generator with no c++ template<> code
- cpp template with CamelNames for structs

### 0.7

- Modifs on `cpp` generated code
    - Removed `.reference` files
    - Added `_forwards` files
    - `gen_` at the begining to indicate you souldn't touch
    - `actions` and `guards` using `cpp templates`
- Better `.dot` generated diagrams
- cpp
    - Removed shadow warning
    - Removed no virtual destructor

### 0.6

- `cpp` generated code with option to move to `error` state
- Instead of `languages`, now we speak about `templates`

### 0.5

- moved to tera templates
- added dot files generation
 
### 0.4

- error redefinied action on cpp (watch example iceberg)
- fix error when running on current directory
- Add full proposed file for hand written .h and .cpp on generated one

### 0.3

- multiline guards with no status name
- multi guard and multi actions
- '\_' on input means any other input
- negative guards
- if no transition, it will generate an error
- updated rust-peg lib and working with macros
- if execption is throwed, we will go to error transition
- better error information
  - on parsing show line
  - check orphans status
- makefile install, test cpp

### 0.2

- Actions
- private hpp (hand file)
- Template functions to specialize on transaction change
- Anonymous `namespace` for functions
- Add comments support on fsm grammar


## Objective

All computer systems interact with the external world by receiving information, processing it, and generating a result.

In addition to communicating with the outside world through `input/output`, it is common for a system to manage a `state`.

These two elements are fundamental in computer systems.

That's why I developed two external DSLs several years ago to simplify these concepts (which I still use in production and find very helpful).

In this repository, I have rewritten one of them: a code generator for state machines.

Currently, it generates C++ code (the most practical to me at the moment ;-).

To explain the system, I will use the example in [cpp_test/fsm](cpp_test/fsm).

This example is about building a system that handles login requests.

The diagram would look like this:

![Basic diagram](basic_diagram.png)

First, the client will require a key to send a request login with a coded password.

This key will be used to encrypt the username and password (the password will go through a hash function) in the login request.

This encryption is irreversible (hash function). The server will perform the same operation (starting from the password hash) to verify its validity.

If it is correct, a login confirmation will be sent.

The DSL representation of this definition would be:

```txt
// Example of an FSM for managing login
// on the server side

[init]
    rq_key              ->  w_login     /   send_key           // this is a comment
    timer               ->  init

[w_login]
    rq_login            ->  login       /   send_login
    timer
        & timeout       ->  error
                        ->  w_login
[login]
    rq_logout           ->  logout      /   send_logout
    heartbeat           ->  login       /   update_hbr
    timer
        & timeout       ->  logout
                        ->  login

[logout]
    timer               ->  logout
    _                   ->  testing     /   send_logout

[error]
    _                   ->  error

[testing]
    rq_key  & ho        ->  logout
                        ->  testing
    _     & hia         ->  login
                        ->  init
```

This program also generates the displayed diagram before using the `DSL`.



## Elements

### States

A `state`machine... you know

### Initial state

```
[init]
```

init, w_login, login, and so on are the states.

Depending on the input and the state (with its values as will be seen later), the system will change to a new state.

### Transition
```
    rq_key                  ->  w_login
```

If we receive an input (in this case _rq_key_), we go to the next state (_w_login_).

## Input

The elements received by the state machine.

```
    INPUT
      v
    rq_key                  ->  w_login
```

In the example, they are rq_key, rq_login, rq_logout, heartbeat, and timer.

### Guards

Functions that will be called depending on the state and input to decide the way forward.

```
                    GUARD
                     v
    rq_login    &   valid   ->  login       /   send_login
``` 

You can have more than one guard.

```
    rq_login    &   valid  &  guard2  ->  login       /   send_login
```

In the example, we have valid, timeout, and ontime.

```
    rq_login
        &   valid   ->  login       /   send_login
                    ->  logout      /   log_err
```

It could be written with a negative guard.

```
    rq_login
        &   !valid  ->  logout      /   log_err
                    ->  login       /   send_login
```

### Final state

After the -> arrow is the state we will change to.

```
                               FINAL_STATE
                                   v
    rq_key                  ->  w_login
```

### Actions

We can define an action to be performed when executing a transaction.

This comes after the final state and '/'.

```
                                                ACTION
                                                  v
    rq_login                ->  logout      /   log_err
```

You can have more than one action.

```
    rq_login                ->  logout      /   log_err  action2
```

In this example, we have _send_key_, _send_login_, and so on.


### Special transition

In all states, it is necessary to consider all inputs.

But it is very common that many transitions are the same (generally error cases).

This is marked with the input _.

Consider the following example status:

```
[init]
    rq_key                      ->  w_login     /   send_key
    timer                       ->  init
    _                           ->  logout      /   log_err
```

`_` means any other input.

Therefore, considering all possible inputs in this state, we have:

```
[init]
    rq_key                      ->  w_login     /   send_key
    timer                       ->  init
    _                           ->  logout      /   log_err
```


## Adapters

_Adapters_ can be placed at the _input_, _guards_, and _transition_ levels.

In the case of _transitions_, they will be placed in the final state.


```
[init]
    rq_key                      ->  w_login     /   send_key|adapter
    timer                       ->  init
    _                           ->  logout      /   log_err
```

The adapters will help us extract common funcionalities, reducing the number of functions to be filled in, or add context information to make the generated code more readable.


## **error** status and implicit transitions

`error` is a special status

You can move to `error` status explicitly.

Any transition no defined, will finis on error status.

You can also put some verifications on transiction funcion, and incase
of fail, you can move to error (even when is not explicitly writted on `fsm`)

This is so, because checking the params, is so commont that adding guards for it, would generate a lot of sound


In our example...

```peg
[init]
    rq_key          ->  w_login     /   send_key
    timer           ->  init
```

There are no transations for `rq_login` and `rq_logout`. Both are implicit and is
equivalent to...

```peg
[init]
    rq_key          ->  w_login     /   send_key
    timer           ->  init
    _               ->  error
```

### Comments

Comments starts at `//` and continues to the end of line

## Usage

To get help...

```bash
fsm_gen --help
```

```txt
> fsm_gen -h

fsm_gen 0.6.1
jleahred

    Generate code from a simple fsm file
    To check the supported templates  --show_templs
    

USAGE:
    fsm_gen [FLAGS] [OPTIONS] [fsm_files]...

FLAGS:
    -d, --dot-graphviz    Generate graphviz dot file
    -h, --help            Prints help information
        --help-cpp        Give me some information about generating cpp files
    -s, --show-templs     Show supported template generators
    -V, --version         Prints version information

OPTIONS:
    -T, --threads <n_threads>    Number of threads to use. 0 means one per core  ;-) [default: 0]
    -t, --templ <templ>          Template to generate code (show available --show-templs) [default: cpp]

ARGS:
    <fsm_files>...    List of fsm files to be processed
```

The default template is `c++` (and at the moment the only one)

You can run:

```bash
fsm_gen login.fsm
```

And it will generate the `c++`

You can pass a list of `fsm` files

```bash
fsm_gen login.fsm  test/seller.fsm test/test2/lift.fsm
```

The code will be generated on same directory of original `.fsm` file

If your shell supports it, you could run...

```bash
fsm_gen **/*.fsm
```

## C++ code generation

It will also generate the files _types.h_, _types_adapters.h_, and _types_forward.h_.

The _types_reference.h_ file serves as a reference for everything generated in the types files.

The _types.h_ file is initially created and will not be overwritten in subsequent executions.

This file will be used to customize the "types".

Directories will be created for `actions`, `guards`, and `transitions`.

The header files will be rewritten and will help avoid "dead code" and provide the new functions to be filled in.


The adapters will be C++ structs with constructors based on the context.

In these types, we have the opportunity to add direct or processed information.

The adapters will help us extract common factors, reducing the number of functions to be filled in, or add context information to make the generated code more readable.


---


soon more detaills











-----



