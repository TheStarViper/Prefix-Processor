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
    FS_createPath: (...args: any[]) => any;
    FS_createDataFile: (...args: any[]) => any;
    FS_preloadFile: (parent: any, name: any, url: any, canRead: any, canWrite: any, dontCreateFile: any, canOwn: any, preFinish: any) => Promise<void>;
    FS_unlink: (...args: any[]) => any;
    FS_createLazyFile: (...args: any[]) => any;
    FS_createDevice: (...args: any[]) => any;
    addRunDependency: (id: any) => void;
    removeRunDependency: (id: any) => void;
};
interface WasmModule {
  _add_numbers(_0: number, _1: number): number;
  _multiply_floats(_0: number, _1: number): number;
  _main(_0: number, _1: number): number;
  _load_dictionary(): number;
  _get_random_word(): number;
}

export type MainModule = WasmModule & typeof RuntimeExports;
export default function MainModuleFactory (options?: unknown): Promise<MainModule>;
