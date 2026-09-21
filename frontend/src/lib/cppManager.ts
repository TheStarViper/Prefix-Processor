import MainModuleFactory from "./cpp/cpp_module";

/**
 * Because some of andrew's c++ functions return a 1 or 0 instead of a boolean
 */
type AndrewBoolean = 0 | 1;

export interface Answer {
	/** the word */
	word: string;

	/** real && response */
	correct: boolean;

	/** a link to merriam webster if it's a real word, and "invalid" otherwise */
	definition: string;

	/** whether the word exists in the dictionary */
	real: boolean;

	/** what the user answered */
	response: boolean;
}

export interface AnswerMetrics {
	count: number;
	correct: number;
	real: number;
	response: number;
}

export class CppManager {
	public fetchWord: () => string = () => "";
	public fetchPrefix: () => string = () => "";
	public submitAnswer: (answer: boolean) => boolean = (t: boolean) => false;
	public getAnswers: () => Answer[] = () => [];

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
		Module._randomize_affix();

		this.fetchWord = Module.cwrap("get_current_base", "string", []);
		this.fetchPrefix = Module.cwrap("fetch_cached_prefix", "string", []);

		const answerBtnPressed: (answer: AndrewBoolean) => AndrewBoolean =
			Module.cwrap("answer_btn_pressed", "number", ["number"]);
		this.submitAnswer = (answer: boolean) => {
			const correct = answerBtnPressed(answer ? 1 : 0);
			this.updateWordAndPrefix();

			return correct === 1;
		};

		const getPrevAnswerWords: () => string = Module.cwrap(
			"get_prev_answer_words",
			"string",
			[],
		);
		const getPrevAnswerCorrectness: () => string = Module.cwrap(
			"get_prev_answer_correctness",
			"string",
			[],
		);
		const getAnswerWordDefitionions: () => string = Module.cwrap(
			"get_answer_word_defitionions",
			"string",
			[],
		);

		this.getAnswers = () => {
			const prevWords = getPrevAnswerWords().split("|");
			const prevCorrects = getPrevAnswerCorrectness()
				.split("|")
				.map((char) => char === "1");
			const prevDefs = getAnswerWordDefitionions().split("|");

			if (
				prevWords.length !== prevCorrects.length &&
				prevWords.length !== prevDefs.length
			) {
				throw new Error("prevWords should be the same length as prevCorrects");
			}

			const prevAnswers: Answer[] = prevWords
				.map((word, index) => {
					const correct = prevCorrects[index];
					const definition = prevDefs[index];

					const real = definition !== "invalid";
					const response = correct === real;

					return { word, correct, definition, real, response };
				})
				.filter(({ word }) => word.trim() !== "");

			return prevAnswers;
		};

		this.updateWordAndPrefix();
	}

	public calcMetrics(answers: Answer[]): AnswerMetrics {
		const metrics: AnswerMetrics = {
			count: 0,
			correct: 0,
			real: 0,
			response: 0,
		};

		for (const { correct, real, response } of answers) {
			metrics.count += 1;

			// I just learned about the unary plus so I wanna use it
			// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Unary_plus
			metrics.correct += +correct;
			metrics.real += +real;
			metrics.response += +response;
		}

		return metrics;
	}
}
