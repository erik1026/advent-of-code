use std::fs;

fn main() {
    let mut floor = 0;
    let mut elf_pos = 0;
    let mut first_basement_hit = false;

    // Read input from file
    let contents = fs::read_to_string("input.txt").expect("Not able to read from file...");

    //println!("Contents:\n{contents}");

    // Part 1
    for (idx, ch) in contents.trim().chars().enumerate() {
        if ch == '(' {
            floor += 1;
        } else if ch == ')' {
            floor -= 1;
        }

        if floor < 0 && first_basement_hit == false {
            elf_pos = idx + 1;
            first_basement_hit = true;
        }
    }
    println!("Ending floor: {floor}");
    println!("Elf that causes first basement occurance: {elf_pos}");
}
