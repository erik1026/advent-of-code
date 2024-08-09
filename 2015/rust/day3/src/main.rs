use std::fs;

const MATRIX_DIMENSION: usize = 1000;

fn move_person(person: &mut [usize; 2], row: isize, column: isize) {
    let new_row = person[0] as isize + row;
    let new_column = person[1] as isize + column;

    if new_row >= 0 && new_column >= 0 {
        person[0] = new_row as usize;
        person[1] = new_column as usize;
    }
}

fn main() {
    // Create a 1000 x 1000 matrix of zeros (false to save memory)
    let mut matrix: Vec<Vec<bool>> = vec![vec![false; MATRIX_DIMENSION]; MATRIX_DIMENSION];
    let row = MATRIX_DIMENSION / 2;
    let column = MATRIX_DIMENSION / 2;

    let mut row_move: isize = 0;
    let mut column_move: isize = 0;

    // Part 2 stuff
    let mut santa = [row, column];
    let mut robo_santa = [row, column];

    let contents = fs::read_to_string("input.txt").expect("Failed to read from the file");

    for (idx, ch) in contents.trim().chars().enumerate() {
        match ch {
            '^' => row_move = -1,
            'v' => row_move = 1,
            '<' => column_move = -1,
            '>' => column_move = 1,
            _ => {}
        }

        if idx % 2 == 0 {
            move_person(&mut santa, row_move, column_move);
            matrix[santa[0]][santa[1]] = true;
        } else {
            move_person(&mut robo_santa, row_move, column_move);
            matrix[robo_santa[0]][robo_santa[1]] = true;
        }

        row_move = 0;
        column_move = 0;
    }

    // Sum up all the true values
    let houses_w_at_least_one_present: usize = matrix
        .iter()
        .flat_map(|row| row.iter())
        .filter(|&&value| value)
        .count();

    println!("Number of houses: {houses_w_at_least_one_present}");
}
