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

const generate_game_question = Module.cwrap('generate_game_question', null, []);
const fetch_cached_prefix = Module.cwrap('fetch_cached_prefix', 'string', []);
const get_current_base = Module.cwrap('get_current_base', 'string', []);
const get_current_is_valid = Module.cwrap('get_current_is_valid', 'number', []);
const randomize_prefix = Module.cwrap('randomize_prefix', 'void', []);
randomize_prefix();
console.log('Generated questions:');
for (let i = 0; i < 10; i++) {

    generate_game_question();
    const prefix = fetch_cached_prefix();
    const base = get_current_base();
    const valid = get_current_is_valid();
    console.log(` - ${prefix} + ${base} = ${valid ? 'valid' : 'invalid'}`);
}

// dictionary load and prefix fetching test #1 ill just keep these around for archive
// const get_random_word_with_prefix = Module.cwrap('get_random_word_with_prefix', 'string', []);
// const randomize_prefix = Module.cwrap('randomize_prefix', 'void', []);
// randomize_prefix();
// console.log('Sample random words with prefix: ');
// for (let i = 0; i < 5; i++) {
//     console.log(' -', get_random_word_with_prefix());
// }

// compile command from parent dir: mingw32-make -C backend
// run command without frontend: node backend/test/run.mjs