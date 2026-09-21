export class TimeManager {
	/**
	 * initial value of seconds, and also size of one progress bar
	 */
	public STARTING_SECONDS = 30;

	/**
	 * seconds to gain upon correct answer
	 */
	public CORRECT_SECONDS = 2;

	/**
	 * seconds to lose upon incorrect answer
	 */
	public INCORRECT_SECONDS = -2;

	public seconds = $state(this.STARTING_SECONDS);
	public elapsedSeconds = $state(0);
	public stillHasTime = $state(true);

	private timer: ReturnType<typeof setTimeout> | null = null;
	public plusClass: undefined | "red" | "green" = $state(undefined);

	constructor() {}

	public init() {
		setInterval(() => {
			if (this.seconds - this.elapsedSeconds > 0) {
				this.elapsedSeconds += 0.1;
			} else {
				this.stillHasTime = false;
			}
		}, 100);
	}

	public get remaining() {
		return this.seconds - this.elapsedSeconds;
	}

	public displayifySeconds(num: number): string {
		const clamped = Math.max(0, num);
		const rounded = Math.round(clamped * 10) / 10;
		return `${rounded}`;
	}

	public debouncedUpdatePlusClass(correctness: boolean) {
		this.plusClass = correctness ? "green" : "red";

		if (this.timer !== null) clearTimeout(this.timer);

		this.timer = setTimeout(() => {
			this.plusClass = undefined;
			this.timer = null;
		}, 1000);
	}
}
