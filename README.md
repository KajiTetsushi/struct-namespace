# struct-namespace
Supposedly way to have features enclosed in dot notation namespaces via structs.

## Disclaimer
You probably don't need to be here. This is a self-learning repo for whatever purposes it may serve. Use it at your own risk.

I don't know what I'm doing (especially in terms of best practices in C).

## Why this exists
I come from the JavaScript / TypeScript domain with experience in React.js / React Native and I want to see how much of my programming experience is "translatable". In React Native, native modules to the JavaScript thread are exported into using the `NativeModules.RN<ModuleName>.<memberMethod>` by convention. This applies to both Java / Kotlin (Android) and Objective-C / Swift (iOS).

This repository exists to investigate namespacing support in C and whether that brings any value to maintainability (for comparison: in TypeScript, namespacing does bring value).

## Setup
You need:
- A CLI terminal that runs Shell scripts (e.g. `bash`, `zsh`).
- A C compiler that can work in CLI (e.g. `gcc`, `clang`).
- A text editor, preferrably one that has an integrated terminal feature (e.g. VScode, Sublime Text).

## Usage
Scripts in `./tools`. Outputs in `./build`.

| Script | Description |
| --- | --- |
| `cleanup.sh` | Removes `./build`. |
| `compile.sh` | Creates the `main` executable. |
| `run.sh` | Launches the `main` executable. |
| `uninstall.sh` | Removes the `main` executable. |

## Development notes
### `struct` used as "namespace"
The `struct` data type can be used to associate a set of functions together if you design it that way. [This Wikipedia article](https://en.wikipedia.org/wiki/Namespace#C) and [this StackOverflow post](https://stackoverflow.com/a/28535585) all point to it being possible.

Some discussion points to macros (`#define`) can't be used as method members, so you're limited to classic functions.

### `const` keyword
When your functions are expected to only access the values of the arguments you pass to it, you can use the `const` keyword ([a blog post](https://matt.sh/sytycc) & [this StackOveflow post](https://stackoverflow.com/a/9419528)) to formally tell the compiler that the values won't change after executing the function.

### `[]` array parameter decays into a `*` pointer
Calculating `sizeof` on a `[]` parameter can be done, but the compiler will print warnings:

```
sizeof on array function parameter will return size of 'int *' instead of 'int []' [-Wsizeof-array-argument]
```

To work around this, the size of the array should be defined by the calling function instead. Ref: [this StackOverflow post](https://stackoverflow.com/a/25680092).
