function solution(info, query) {
    const answer = [];
    const combinations = {};

    const combination = (array, score, start) => {
        const key = array.join("");
        const value = combinations[key];

        if (value) {
            combinations[key].push(score);
        } else {
            combinations[key] = [score];
        }

        for (let i = start; i < array.length; i++) {
            const temp = [...array];
            temp[i] = "-";
            combination(temp, score, i + 1);
        }
    };
    info.map((i) => {
        const splited = i.split(" ");
        const score = Number(splited.pop());
        combination(splited, score, 0);
    });

    Object.keys(combinations).map((key) => {
        combinations[key] = combinations[key].sort((a, b) => a - b);
    });

    return query.reduce((result, e) => {
        const splited = e.replace(/ and /g, " ").split(" ");
        const score = Number(splited.pop());
        const key = splited.join("");
        const array = combinations[key];

        if (array) {
            let start = 0;
            let end = array.length;
            while (start < end) {
                const mid = Math.floor((start + end) / 2);

                if (array[mid] >= score) {
                    end = mid;
                } else if (array[mid] < score) {
                    start = mid + 1;
                }
            }

            const count = array.length - start;
            result.push(count);
        } else {
            result.push(0);
        }
        return result;
    }, answer);
}
