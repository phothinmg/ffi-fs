const path = require("node:path");
const { suffix, dlopen } = require("node:ffi");

const ffifs = (function () {
    const binaryPath = path.resolve(process.cwd(), `lib/ffifs.${suffix}`);

    const { lib, functions } = dlopen(binaryPath, {
        readFile: { arguments: ["string", "pointer", "uint32"], return: "uint32" },
        writeFile: { arguments: ["string", "string"], return: "void" },
    });
    const _ = {
        readFile(filePath) {
            const buffer = Buffer.alloc(1024 * 1024);
            const length = functions.readFile(filePath, buffer, buffer.length);
            return buffer.toString("utf8", 0, length);
        },
        writeFile(filePath, content) {
            functions.writeFile(filePath, content);
        },
    };
    return _;
})();

module.exports = ffifs;
