import re
def solution(word, pages):
    answer = 0
    name = [0] * len(pages)
    basic = [0] * len(pages)
    extern = [[]* n for n in range(len(pages))]
    #basic score
    for a in range(len(pages)):
        mod = re.sub('[^a-zA-Z]', '.', pages[a]).split('.')
        for x in mod:
            if len(x) == len(word):
                if x.lower() == word.lower():
                    basic[a] += 1
    for a in range(len(pages)):
        met = re.findall("<meta.+/>",pages[a])
        meta= re.findall('https.+\"', met[0])
        name[a] = meta[0].replace('\"', '')

        hre = re.findall("<a.+?>",pages[a])
        for b in range(len(hre)):
            href = re.findall('https.+\"', hre[b])
            extern[a].append(href[0].replace('\"', ''))
    score = [0] * len(pages)
    score = list(map(lambda x,y: x+y, basic,score))
    e_score = [0] * len(pages)
    for x in range(len(e_score)):
        if not len(extern[x]) == 0:
            e_score[x] = basic[x] / float(len(extern[x]))
        else:
            e_score[x] = 0
    for a in range(len(extern)):
        for b in range(len(extern[a])):
            for c in range(len(name)):
                if extern[a][b] == name[c]:
                    score[c] += e_score[a]
    # print(name)
    # print('basic : ', basic)
    # print(extern)
    # print('link : ', e_score)
    # print('total: ', score)
    return score.index(max(score))