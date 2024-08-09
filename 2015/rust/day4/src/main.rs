use md5;

fn main() {
    let puzzle_input = "bgvyzdsv".to_string();

    let mut answer = 0;

    loop {
        let mut puzzle_input_clone = puzzle_input.clone();
        puzzle_input_clone.push_str(answer.to_string().as_str());

        let digest = md5::compute(puzzle_input_clone);
        let hash = format!("{:x}", digest);

        if &hash[..5] == "00000" {
            break;
        }

        answer += 1;
    }

    println!("{answer}");
}
