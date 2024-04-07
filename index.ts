import { Worker } from "node:worker_threads";
import { foo } from "./cpplib/Main.wasm";

console.log(foo());