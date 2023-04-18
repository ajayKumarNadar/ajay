const d = new Date();
let year = d.getFullYear();
$('#year').text(year);

$(window).scroll(function() {
  let activeLinkText = $(".nav-link.active").text();
  console.log(activeLinkText);
  $(".navbar-text").text(" / "+activeLinkText);
});
