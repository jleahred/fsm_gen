.PHONY: test
test:
	cargo run -- ./cpp_test/fsm/login.fsm

.PHONY: install
install:
	cargo install --path . -f
