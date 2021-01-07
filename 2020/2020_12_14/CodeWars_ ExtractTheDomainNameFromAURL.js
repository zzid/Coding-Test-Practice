function domainName(url) {
  url = url.replace(/(http:\/\/|https:\/\/|www.)/g, '');
  return url.split('.')[0];
}
