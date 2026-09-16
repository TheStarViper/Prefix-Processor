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
