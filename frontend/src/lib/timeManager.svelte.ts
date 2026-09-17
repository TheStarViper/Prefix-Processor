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
	public INCORRECT_SECONDS = -5;

	public seconds = $state(this.STARTING_SECONDS);
	public elapsedSeconds = $state(0);
	public stillHasTime = $state(true);

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
}
