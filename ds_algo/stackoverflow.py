from pytrends.request import TrendReq
pytrend = TrendReq(hl='de', tz=390, retries=10, backoff_factor=0.5)

keywords = ['foo', 'bar', 'dummy']

for keyword in keywords:
  try:
    pytrend.build_payload(
      kw_list=[keyword],
      geo='DE',
      timeframe = 'now 1-d')
    gbl = globals()
    for i in range(len(keywords)):
        gbl['df_'+str(i)] = pytrend.interest_over_time()
        gbl['df_'+str(i)] = gbl['df_'+str(i)].drop(labels=['isPartial'],axis='columns')
    print(keyword + ' was succesfully pulled from Google Trends')
  except Exception as e:
    print(keyword + ' was not successfully pulled because of the following error: ' + str(e))
    continue