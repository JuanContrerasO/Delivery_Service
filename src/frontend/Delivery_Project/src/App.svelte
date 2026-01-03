<script>
  let distance = 120;
  let speed = 60;
  let result = null;
  let loading = true;
  let computeTimeFn; // local reference instead of window

  async function loadWasm() {
    const module = await new Promise((resolve) => {
      const script = document.createElement("script");
      script.src = "/wasm/trip.js";
      script.onload = () => resolve(window.Module);
      document.body.appendChild(script);
    });

    await module.ready;

    computeTimeFn = module.cwrap("compute_time", "number", ["number", "number"]);
    loading = false;
  }

  function compute() {
    if (!computeTimeFn) return;
    result = computeTimeFn(Number(distance), Number(speed));
  }

  loadWasm();
</script>

<main>
  <h1>Delivery Time Calculator</h1>

  {#if loading}
    <p>Loading WASM...</p>
  {:else}
    <label>
      Distance (miles):
      <input type="number" bind:value={distance} min="0" />
    </label>

    <label>
      Speed (mph):
      <input type="number" bind:value={speed} min="0" />
    </label>

    <button on:click={compute}>
      Compute Time
    </button>

    {#if result !== null}
      <p>Total time: {result} hours</p>
    {/if}
  {/if}
</main>
