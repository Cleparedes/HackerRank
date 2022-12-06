use std::io::{self, BufRead};

fn grid_challenge(grid: &[String]) -> String {
    let n = grid.len();
    match n {
        1 => String::from("YES"),
        _ => {
            let mut s0:Vec<char> = grid[0].chars().collect();
            s0.sort();
            let m = s0.len();
            for i in 1..n {
                let mut si:Vec<char> = grid[i].chars().collect();
                si.sort();
                for j in 1..m {
                    if s0[j] > si[j] {
                        return String::from("NO");
                    }
                }
                s0 = si;
            }
            String::from("YES")
        },
    }
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let t = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

    for _ in 0..t {
        let n = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

        let mut grid: Vec<String> = Vec::with_capacity(n as usize);

        for _ in 0..n {
            let grid_item = stdin_iterator.next().unwrap().unwrap();
            grid.push(grid_item);
        }

        let result = grid_challenge(&grid);

        println!("{}", result);
    }
}