import { fileURLToPath } from 'node:url';
import path from 'node:path';
import createModule from '../../frontend/src/lib/cpp/cpp_module.js'; 

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const moduleDir = path.resolve(__dirname, '../../frontend/src/lib/cpp');

const Module = await createModule({
    locateFile: (filename) => path.join(moduleDir, filename),
});

const load_dictionary = Module.cwrap('load_dictionary', 'number', []);
const get_random_word = Module.cwrap('get_random_word', 'string', []);

const success = load_dictionary();
console.log('words loaded:', success);

if (!success) {
    console.log('Dictionary failed to load - check the /assets path and CSV parsing.');
    process.exit(1);
}


const get_random_word_with_prefix = Module.cwrap('get_random_word_with_prefix', 'string', []);
const randomize_prefix = Module.cwrap('randomize_prefix', 'void', []);
randomize_prefix();
console.log('Sample random words with prefix: ');
for (let i = 0; i < 5; i++) {
    console.log(' -', get_random_word_with_prefix());
}

// compile command from parent dir: mingw32-make -C backend
// run command without frontend: node backend/test/run.mjs