# FFI FS

![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/phothinmg/ffi-fs/ffi.yml?style=for-the-badge&label=Build%20and%20Test%20Cross-Platform%20FFI%20Binaries)

## Overview

FFI FS demonstrates using Node.js's built-in, experimental Foreign Function Interface via the `node:ffi` module.

This repository contains examples and helper code to call native functions from Node.js when Node is built with FFI support.

## Requirements

- A Node.js build with FFI enabled. Node.js with FFI support is experimental and may not be available in all releases — Node JS version `v26.2.0` or later is recommended.
- Run Node with the `--experimental-ffi` flag (for example: `node --experimental-ffi`).
- A platform/architecture where Node's FFI is supported (x64/arm64 on Linux, macOS, and Windows builds that include FFI).

## Usage

- Clone the repository:

```sh
 git clone https://github.com/phothinmg/ffi-fs.git
 cd ffi-fs
```

- Install dependencies:

```sh
 npm i
```

## Safety and Security

- The `node:ffi` API is unsafe. Passing invalid pointers, using an incorrect symbol signature, or accessing memory after it has been freed can crash the process or corrupt memory.
- Use extreme caution when working with raw pointers and native memory. Validate inputs and avoid using dangling pointers.
- Do not run untrusted native code.

## Contributing

Contributions are welcome. Please open an issue or a pull request to discuss changes.

## License

This project is available under the terms of the LICENSE file in this repository.
