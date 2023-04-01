# RDCalc
`RDCalc` is a simple, recursive descent-based CLI calculator. It analyzes mathematical expression using grammars and calculates the result.

## Usage
You can run `RDCalc` with (also see [Building from source](https://github.com/nerett/rd_calculator#building-from-source))

```shell
make run <math expression>$
```

Supported symbols: `(`, `)`, `*`, `/`, `+`, `-` and numbers. You have to put `$` in the end of expression.
Use `make rund` instead to run in debug mode.

## Building from source
Download this repository with

```shell
git clone https://github.com/nerett/rd_calculator.git
```

Build it with

```shell
cd rd_calculator/
make
```

To totally rebuild the project run

```shell
make clean
make
```

## Documentation
This section isn't done yet.

## About project
This programm was written during MIPT **Ded's** cource.
