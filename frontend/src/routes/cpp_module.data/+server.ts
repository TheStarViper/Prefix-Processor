/**
 * cpp_module.data needs to be in lib/cpp to make andrew's backend tests work,
 * but it also needs to be present in the frontend at runtime.
 * This endpoint just proxies the file, which tells sveltekit to prerenderer it
 * and makes it available.
 */

import { read } from "$app/server";
import dataURL from "$lib/cpp/cpp_module.data?url";

export const prerender = true;

export async function GET() {
	const response = read(dataURL);

	return new Response(await response.arrayBuffer(), {
		headers: {
			"content-type": "text/plain",
		},
	});
}
