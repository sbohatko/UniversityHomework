import { readJson } from 'https://raw.githubusercontent.com/denoland/deno/v1.0.0-rc2/std/fs/read_json.ts'
import { Application, Router } from "https://deno.land/x/oak/mod.ts";
const { args, stat, readDir, open, exit ,readFile} = Deno;

const data = await readJson("./data.json");
const file = await readFile('cat.jpg');

const router = new Router();
router
  .get("/", (context) => {
    context.response.body = file;
  })
  .get("/data", (context) => {
    context.response.body = data;
  })

const app = new Application();
//Logger
app.use(async (ctx, next) => {
  await next();
  const rt = ctx.response.headers.get("X-Response-Time");
  console.log(`${ctx.request.method} ${ctx.request.url} - ${rt}`);
});

// Timing
app.use(async (ctx, next) => {
  const start = Date.now();
  await next();
  const ms = Date.now() - start;
  ctx.response.headers.set("X-Response-Time", `${ms}ms`);
});

// Image
app.use((ctx) => {
  ctx.response.body = file;
});
app.use(router.routes());
app.use(router.allowedMethods());

await app.listen({ port: 8000 });