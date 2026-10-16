// Wheel paging: one wheel step (or trackpad flick) moves exactly one page.
// Touch and keyboard scrolling use the CSS scroll snapping in style.css.
(() => {
  const pages = [...document.querySelectorAll(".page")];
  if (pages.length < 2) return;
  const reduced = matchMedia("(prefers-reduced-motion: reduce)").matches;
  let busyUntil = 0, lastWheel = 0;

  const currentIndex = () => {
    let i = 0;
    pages.forEach((p, k) => { if (p.offsetTop <= scrollY + 2) i = k; });
    return i;
  };

  addEventListener("wheel", (e) => {
    if (e.ctrlKey || Math.abs(e.deltaY) < Math.abs(e.deltaX)) return;
    const now = performance.now();
    const gap = now - lastWheel;
    lastWheel = now;
    const dir = Math.sign(e.deltaY);
    if (!dir) return;
    const i = currentIndex(), page = pages[i];
    // Pages taller than the window scroll normally until their edge
    const bottom = page.offsetTop + page.offsetHeight;
    if (dir > 0 && scrollY + innerHeight < bottom - 2) return;
    if (dir < 0 && scrollY > page.offsetTop + 2) return;
    e.preventDefault();
    // Ignore the tail of a trackpad flick and anything during the page transition
    if (now < busyUntil || gap < 60) return;
    const target = pages[i + dir];
    if (!target) return;
    busyUntil = now + 700;
    scrollTo({ top: dir > 0 ? target.offsetTop : Math.max(target.offsetTop, target.offsetTop + target.offsetHeight - innerHeight), behavior: reduced ? "auto" : "smooth" });
  }, { passive: false });
})();
