fn main() {
    let quotes = [
        "On Earth there is no poverty, no crime, no war. You look out the window at Starfleet Headquarters and you see paradise. Well, it's easy to be a saint in paradise. But the Maquis do not live in paradise. Out there, in the Demilitarized Zone, all problems have not been solved yet. There are no saints, just people; angry, scared, determined people who are going to do whatever it takes to survive, whether it meets with Federation approval or not!",
        "You know, there are some words I've known since I was a schoolboy: \"With the first link, the chain is forged. The first speech censured, the first thought forbidden, the first freedom denied, chains us all irrevocably.\" Those words were uttered by Judge Aaron Satie, as wisdom and warning. The first time any man's freedom is trodden on, we're all damaged.",
        "Find him and kill him! - Worf",
    ];
    for quote in quotes.iter() {
        print!("{}\n\n", quote)
    }
}
