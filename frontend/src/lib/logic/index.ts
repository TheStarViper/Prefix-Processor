import * as placeholders from "./placeholders";

export const getWord: () => string = placeholders.placeholderGetWord;
export const getPrefix: () => string = placeholders.placeholderGetPrefix;
export const isValid: (word: string, prefix: string) => boolean =
	placeholders.placeholderIsValid;
