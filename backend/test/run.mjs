import createModule from '../../frontend/src/lib/cpp/cpp_module.js'; 

const Module = await createModule();

const loadDictionary = Module.cwrap('loadDictionary', 'number', []);
const getRandomWord = Module.cwrap('getRandomWord', 'string', []);

const success = loadDictionary();
console.log('loadDictionary() returned:', success);

if (!success) {
    console.log('Dictionary failed to load — check the /assets path and CSV parsing.');
    process.exit(1);
}

console.log('Sample random words:');
for (let i = 0; i < 10; i++) {
    console.log(' -', getRandomWord());
}

// compile command from parent dir: mingw32-make -C backend
// run command without frontend: node backend/test/run.mjs