//
// placeholders until the backend is ready
//

export function placeholderGetWord(): string {
	const words = [
		"orthodox",
		"appointment",
		"retiree",
		"chalk",
		"bike",
		"disessay",
		"company",
		"able",
		"improvement",
		"boat",
	];

	const idx = Math.floor(Math.random() * words.length);

	return words[idx];
}

export function placeholderGetPrefix(): string {
	return "dis";
}

export function placeholderIsValid(word: string, prefix: string): boolean {
	if (prefix === "dis") {
		const validDisWords = ["appointment", "company", "able", "disimprovement"];
		return validDisWords.includes(word);
	} else {
		throw new Error("isValid can only handle the prefix 'dis' rn");
	}
}
