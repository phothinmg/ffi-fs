# FFI FS

![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/phothinmg/ffi-fs/ffi.yml?style=for-the-badge&label=Build%20and%20Test%20Cross-Platform%20FFI%20Binaries)

## Overview

- This project try to use Node.js features a built-in, experimental foreign function interface via the [node:ffi](https://nodejs.org/api/ffi.html) module.
- `node:ffi` API is unsafe. Passing invalid pointers, using an incorrect symbol signature, or accessing memory after it has been freed can crash the process or corrupt memory.
- Only available under the `node:` scheme in builds with FFI support and is gated by the --experimental-ffi flag
