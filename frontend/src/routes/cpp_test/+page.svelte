<script lang="ts">
	import MainModuleFactory from "$lib/cpp/cpp_module";
	import { onMount } from "svelte";

	let addRes: number = $state(0);
	let multRes: number = $state(0);

	onMount(async () => {
		const Module = await MainModuleFactory();

		addRes = Module._add_numbers(3, 4);
		multRes = Module._multiply_floats(3, 4);
	});
</script>

<h1>test of importing a function from c++</h1>

<p>add_numbers test: 3 + 4 = {addRes}</p>
<p>multiply_floats test: 3 * 4 = {multRes}</p>
