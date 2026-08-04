declare module "ffifs" {
  export function readFile(filePath: string): string;
  export function writeFile(filePath: string, content: string): void;
}
