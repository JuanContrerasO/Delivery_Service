import Module from "../build/trip.js";

Module().then((instance) => {
  const computeTime = instance.cwrap(
	"compute_time",
	"number",
	["number", "number"]
  );
  
  console.log(computeTime(120,60)); //expect 2
});
