/*
Copyright 11/05/2025 https://github.com/su8/nitruks
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA.
*/
use std::env;
use std::process;

fn variants(word: &str) -> Vec<String> {
    let mut result = Vec::new();
    result.push(word.to_string());
    if !word.is_empty() {
        let mut capitalized = word.to_string();
        if let Some(first_char) = capitalized.get_mut(0..1) { first_char.make_ascii_uppercase(); }
        result.push(capitalized);
    }
    result.push(word.to_uppercase());
    result
}

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 6 { process::exit(1); }
    let mut usernames = vec!["frost".to_string()];
    let mut roles = Vec::new();
    let separators = vec!["".to_string(), "_".to_string()];
    if args[1].starts_with('-') && args[1].contains('f') { usernames = vec![args[2].clone()]; }
    if args[3].starts_with('-') && args[3].contains('o') { for x in (4..args.len()).rev() { roles.push(args[x].clone()); } }
    for username in &usernames {
        for role in &roles {
            for sep in &separators {
                for user in variants(username) {
                    for r in variants(role) {
                        println!("{}{}{}", user, sep, r);
                    }
                }
            }
        }
    }
}