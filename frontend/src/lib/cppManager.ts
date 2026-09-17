import MainModuleFactory from "./cpp/cpp_module";

/**
 * Because some of andrew's c++ functions return a 1 or 0 instead of a boolean
 */
type AndrewBoolean = 0 | 1;
function andrewifyBool(bool: boolean): AndrewBoolean {
	return bool ? 1 : 0;
}
function deAndrewifyBool(aBool: AndrewBoolean): boolean {
	return aBool === 1;
}

export class CppManager {
	public fetchWord: () => string = () => "";
	public fetchPrefix: () => string = () => "";
	public submitAnswer: (answer: boolean) => boolean = (t: boolean) => false;

	constructor(
		private setWord: (newWord: string) => void,
		private setPrefix: (newPrefix: string) => void,
	) {}

	public updateWordAndPrefix() {
		this.setWord(this.fetchWord());
		this.setPrefix(this.fetchPrefix());
	}

	public async init() {
		const Module = await MainModuleFactory();

		Module._load_dictionary();
		Module._generate_game_question();
		Module._randomize_prefix();

		this.fetchWord = Module.cwrap("get_current_base", "string", []);
		this.fetchPrefix = Module.cwrap("fetch_cached_prefix", "string", []);

		const submitAnswerAndrewified: (answer: AndrewBoolean) => AndrewBoolean =
			Module.cwrap("answer_btn_pressed", "number", ["number"]);
		this.submitAnswer = (answer: boolean) => {
			const correct = submitAnswerAndrewified(andrewifyBool(answer));
			this.updateWordAndPrefix();

			return deAndrewifyBool(correct);
		};

		this.updateWordAndPrefix();
	}
}
