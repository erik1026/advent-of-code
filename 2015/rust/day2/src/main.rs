use std::fs;

fn compute_wrapping_needed(length: u32, width: u32, height: u32) -> u32 {
    let mut total_wrapping = 0;

    let sides_array = [length * width, length * height, width * height];

    if let Some(min_side) = sides_array.iter().min() {
        total_wrapping += min_side;
    }

    let sum_of_sides: u32 = sides_array.iter().sum();

    total_wrapping += sum_of_sides * 2;

    total_wrapping
}

// We are assuming that the first two parameters are the smallest two
fn compute_ribbon_needed(length: u32, width: u32, height: u32) -> u32 {
    let mut total_ribbon = 0;

    let mut smallest_side = length;
    let mut second_smallest_side = width;

    if smallest_side > second_smallest_side {
        std::mem::swap(&mut smallest_side, &mut second_smallest_side);
    }

    if height < smallest_side {
        second_smallest_side = smallest_side;
        smallest_side = height;
    } else if height < second_smallest_side {
        second_smallest_side = height;
    }

    total_ribbon += length * width * height;
    total_ribbon += (2 * smallest_side + 2 * second_smallest_side);

    total_ribbon
}

fn main() {
    let mut total_wrapping_needed = 0;
    let mut total_ribbon_needed = 0;

    let contents = fs::read_to_string("input.txt").expect("Failed to read from file");

    for line in contents.trim().lines() {
        let split_line: Vec<u32> = line
            .split('x')
            .map(|s| s.parse().expect("Failed to parse a value"))
            .collect();

        total_wrapping_needed +=
            compute_wrapping_needed(split_line[0], split_line[1], split_line[2]);

        total_ribbon_needed += compute_ribbon_needed(split_line[0], split_line[1], split_line[2]);
    }

    println!("Total amount of wrapping paper in sqft: {total_wrapping_needed}");
    println!("Total amount of ribbon needed: {total_ribbon_needed}");
}
