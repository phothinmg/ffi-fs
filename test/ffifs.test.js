const fs = require("node:fs");
const { it, describe } = require("node:test");
const assert = require("node:assert");
const { suffix } = require("node:ffi");
const ffifs = require("../index.js");

describe("FFI FS tests", () => {
    it("Read File", () => {
        const result = ffifs.readFile("test/test.txt");
        assert.deepEqual(result, "Hello");
    });
    it("Write File", () => {
        const outFile = "test/test2.txt";
        if (fs.existsSync(outFile)) {
            fs.rmSync(outFile);
        }
        ffifs.writeFile(outFile, "Hello");
        const result = fs.existsSync(outFile);
        assert.deepEqual(result, true);
    });
});
