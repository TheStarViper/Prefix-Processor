// TypeScript bindings for emscripten-generated code.  Automatically generated at compile time.
declare var RuntimeExports: {
    /**
     * @param {string|null=} returnType
     * @param {Array=} argTypes
     * @param {Array=} args
     * @param {Object=} opts
     */
    ccall: (ident: any, returnType?: (string | null) | undefined, argTypes?: any[] | undefined, args?: any[] | undefined, opts?: Object | undefined) => any;
    /**
     * @param {string=} returnType
     * @param {Array=} argTypes
     * @param {Object=} opts
     */
    cwrap: (ident: any, returnType?: string | undefined, argTypes?: any[] | undefined, opts?: Object | undefined) => any;
};
interface WasmModule {
  _add_numbers(_0: number, _1: number): number;
  _multiply_floats(_0: number, _1: number): number;
  _main(_0: number, _1: number): number;
}

export type MainModule = WasmModule & typeof RuntimeExports;
export default function MainModuleFactory (options?: unknown): Promise<MainModule>;
