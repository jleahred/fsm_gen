# FSM generator

## Installation

Pending to upload to crates.io

## TODO

- Add log method (template on c++)
- parallel running
- Consider \_ input for default behavior on not declared inputs
- Complete the cpp example and update on README.md
- Check fsm format
  - inputs
  - transitions without guards
- Upload to crates.io
- Force generate files (at the moment gen files are created always)
- Support for multiple guards
- output with signals
- generate dot files for graphviz

- Add languages

## Aim

All computing processes consist of receiving an input and processing it by generating an output. From the simplest to the most complex.

Sometimes, the process depends on the context and it is necessary to manage a state.

Messages and state management, therefore, are two fundamental elements of any software process.

That's why I wrote two external DSLs long time ago for both elements (which I still use in production and are a great help).

In this repository I rewrite one of them, the code generator for a state machine.

At the moment it generates C++ code (my most immediate target in production).

To explain the system, I will use the example in [cpp_test/fsm](cpp_test/fsm)

This example is about writing a system that will handle login requests.

First the server will be asked for a password.

This key will be used to encode the username and password (this one will be passed through a hash function) in the login request.

This encoding will be irreversible (hash function). The server will perform the same operation (starting from the hash of the password) to verify the validity.

If it is OK, it will send a login confirmation.

The diagram would look like this:

![Basic diagram](basic_diagram.png)

A full list of transitions could be written as:

```peg
[init]
    rq_key                  ->  w_login     /   send_key
    rq_login                ->  logout      /   log_err
    rq_logout               ->  logout      /   log_err
    heartbeat               ->  logout      /   log_err
    timer                   ->  init

[w_login]
    rq_key                  ->  logout      /   log_err
    rq_login    &   valid   ->  login       /   send_login
    rq_login                ->  logout      /   log_err
    rq_logout               ->  logout      /   log_err
    heartbeat               ->  logout      /   log_err
    timer       &   timeout ->  logout      /   log_err
    timer                   ->  w_login

[login]
    rq_key                  ->  logout      /   log_err
    rq_login                ->  logout      /   log_err
    rq_logout               ->  logout      /   send_logout
    heartbeat               ->  logout      /   log_err
    timer       &   on_time ->  login
    timer                   ->  logout

[logout]
    rq_key                  ->  logout      /   log_err
    rq_login                ->  logout      /   log_err
    rq_logout               ->  logout      /   logout
    heartbeat               ->  logout      /   log_err
    timer                   ->  logout      /   log_err
```

And this is the input for this tool to generate code

### Elements

#### States

```peg
[init]
    ...
```

**init**, **w_login**, **login** ... are the states

Depending on the input and the state (with its values as will be seen later), the system will change to a new state.

#### Transition

```peg
    rq_key                  ->  w_login
```

If we receive an input (in this case `rq_key`) we go to next state (`w_login`)

#### INPUT

The elements received by the status machine.

```peg
    INPUT
      v
    rq_key                  ->  w_login
```

In the example they are **rq_key**, **rq_login**, **rq_logout**, **heartbeat** and **timer**.

#### GUARDS

Functions that will be called depending on the status and input to decide the way forward.

```peg
                    GUARD
                     v
    rq_login    &   valid   ->  login       /   send_login
```

In the example we have **valid**, **timeout**, **ontime**.

All transitions can be replicated with different guards, but always one of
them has to be without guard (and the last one). Example:

```peg
    rq_login    &   valid   ->  login       /   send_login
    rq_login                ->  logout      /   log_err
```

#### Final status

Behind the **->** arrow is the state we will change to.

```peg
                               FINAL_STATUS
                                   v
    rq_key                  ->  w_login
```

#### Actions

We can define an action to be performed when executing a transaction.

This will be after the final state and '/'.

```peg
                                                ACTION
                                                  v
    rq_login                ->  logout      /   log_err
```

In this example we have **send_key**, **send_login**...

## Usage

To get help...

```bash
fsm_gen --help
```

```
fsm_gen 0.1.0
jleahred <jleahred@gmail.com>

    Generate code from a simple fsm file
    To check the supported languages  --show_langs


USAGE:
    fsm_gen [FLAGS] [OPTIONS] [fsm_files]...

FLAGS:
    -f, --force         Generate all files regardless of change date
    -h, --help          Prints help information
        --help-cpp      Give me some information about generating cpp files
    -s, --show-langs    Show supported languages generators
    -V, --version       Prints version information

OPTIONS:
    -l, --lang <lang>    Language to generate code (show available --show-langs) [default: cpp]

ARGS:
    <fsm_files>...    List of fsm files
```

The default language is `c++` (and at the moment the only one)

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

If your shell supports it you could run...

```bash
fsm_gen **/*.fsm
```

## C++ code generation

Starting from the example `login.fsm` the system will create...

```
    fsm_login_gen.h
    fsm_login_gen.cpp
```

You don't have to modify these files. You have to write your code
on next files...

```
    fsm_login.h
    fsm_login.cpp
```

These two files will be created if don't exist as a reference

### fsm_login_gen.h

Full code on [cpp_test/fsm/fsm_login_gen.h](cpp_test/fsm/fsm_login_gen.h)

We are informed on when it was created.

This file is automatically generated and you don't need to modify it,
but it's a good point to see the `API` and prepare the code you have
to fill by hand

```cpp
//  generated automatically  2019-03-22 11:24:40
//  do not modify it manually
```

Headers and namespaces based on filename

```cpp
#ifndef FSM_FSM_LOGIN_GENERATED_H
#define FSM_FSM_LOGIN_GENERATED_H

#include <iostream>
#include <memory>

namespace login {
```

Forward declaration of types and a tip to know where to fill it

First with status, and next the inputs

```cpp
//  ----------------------------------------------------
//      M A N U A L

//  declaration on fsm_login.h
//  forward_status_info
struct init_info_t;
struct w_login_info_t;
struct login_info_t;
struct logout_info_t;


//  in
struct heartbeat_t;
struct rq_key_t;
struct rq_login_t;
struct rq_logout_t;
struct timer_t;


//      M A N U A L
//  ----------------------------------------------------
```

Internal clase forward declaration

```cpp
class BaseState;
typedef std::shared_ptr<BaseState> SState;
```

The `fsm` class you have to instanciate

```cpp
//  -------------------
//      F S M
class Fsm {
public:
  Fsm();
  ~Fsm();

  void in(const heartbeat_t& in);
  void in(const rq_key_t& in);
  void in(const rq_login_t& in);
  void in(const rq_logout_t& in);
  void in(const timer_t& in);

  ...
}
```

Methods of `Fsm` class to be defined by hand

First the funtions to generate new state

Next the `guards` funtions

```cpp

  //  ----------------------------------------------------
  //      M A N U A L

  //  implementation in fsm_login.cpp

  //  status change functions
  logout_info_t in2logout(const heartbeat_t& i);
  logout_info_t in2logout(const rq_key_t& i);
  w_login_info_t in2w_login(const rq_key_t& i);
  login_info_t in2login(const rq_login_t& i);
  logout_info_t in2logout(const rq_login_t& i);
  logout_info_t in2logout(const rq_logout_t& i);
  init_info_t in2init(const timer_t& i);
  login_info_t in2login(const timer_t& i);
  logout_info_t in2logout(const timer_t& i);
  w_login_info_t in2w_login(const timer_t& i);


  //  guards to implement
  bool valid(const rq_login_t& in, const  w_login_info_t& st_info);
  bool timeout(const timer_t& in, const  w_login_info_t& st_info);
  bool on_time(const timer_t& in, const  login_info_t& st_info);


  //      M A N U A L
  //  ----------------------------------------------------

```

### fsm_login_gen.cpp

Full code on [cpp_test/fsm/fsm_login_gen.cpp](cpp_test/fsm/fsm_login_gen.cpp)

You must not modify this file, and it's not necessary to know much about it

### fsm_login.h

Full code on [cpp_test/fsm/fsm_login.h](cpp_test/fsm/fsm_login.h)

In this file you have to declare the status info types, and input types

If the file doesn't exist, it will be created with empty data types

```cpp
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference
```

The header guard based on fsm file and a reference to the generated header

```cpp
#ifndef FSM_LOGIN_H
#define FSM_LOGIN_H

#include <string>

#include "fsm_login_gen.h"

```

On namespace based on fsm file, we have the two types to declare

You can, of course, complete these types on cpp file if necessary

```cpp
namespace login {

  //  status info types
  struct init_info_t{};
  struct w_login_info_t{};
  struct login_info_t{};
  struct logout_info_t{};


  //  input types
  struct heartbeat_t {};
  struct rq_key_t {};
  struct rq_login_t {};
  struct rq_logout_t {};
  struct timer_t {};


} // namespace login
#endif // FSM_LOGIN_H
```

### fsm_login.cpp

Full code on [cpp_test/fsm/fsm_login.cpp](cpp_test/fsm/fsm_login.cpp)

This is the other file you have to maintain by hand.

This methods, are declared on `.h` and annotated you have to fill by hand.

```cpp
//  Code generated automatically to be filled manually
//  This file will not be updated by generator
//  It's created just the first time as a reference

#include "fsm_login.h"
#include "fsm_login_gen.h"

namespace login {

    //  status change functions
    logout_info_t in2logout(const heartbeat_t& i){}
    logout_info_t in2logout(const rq_key_t& i){}
    w_login_info_t in2w_login(const rq_key_t& i){}
    login_info_t in2login(const rq_login_t& i){}
    logout_info_t in2logout(const rq_login_t& i){}
    logout_info_t in2logout(const rq_logout_t& i){}
    init_info_t in2init(const timer_t& i){}
    login_info_t in2login(const timer_t& i){}
    logout_info_t in2logout(const timer_t& i){}
    w_login_info_t in2w_login(const timer_t& i){}


    //  guards
    bool valid(const rq_login_t& in, const  w_login_info_t& st_info) { return true; }
    bool timeout(const timer_t& in, const  w_login_info_t& st_info) { return true; }
    bool on_time(const timer_t& in, const  login_info_t& st_info) { return true; }



} // namespace login
```

### login

You will have a template that will be called on every state transition.

```cpp
    //  log
template <typename IN, typename INIT_ST, typename END_ST>
void log(const std::string &context, const IN &, const INIT_ST &, const END_ST &) {
  std::cout << context << std::endl;
}

} // namespace login
#endif // FSM_LOGIN_H
```

You can specialize it as much as you want.

The first parameter is a text with the description of the transition. Example:

```cfg
[init] rq_key -> w_login
[w_login] rq_login(valid) -> login
[login] rq_logout -> logout
```

## Diagram source

```
basic diagram
digraph finite_state_machine {
	rankdir=LR;
	size="8,5"
	node [shape = circle, width=1];

    init        ->  w_login [label="rq_key"]
    init        ->  logout  [label="_"]

    w_login     ->  login   [label="rq_login ok"]
    w_login     ->  logout  [label="rq_login invalid"]
    w_login     ->  logout  [label="_"]

    login       ->  logout  [label="rq_logout"]
    login       ->  logout  [label="_"]
}
```
