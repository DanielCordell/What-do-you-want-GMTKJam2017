#include <SFML/Window/Event.hpp>
#include "Game.h"
#include <iostream>

Game::Game(): shouldQuit(false), window(sf::VideoMode(1280, 720), "Hello", sf::Style::Close) {
	nodes[0] = Node::create(1, -1, 2);
	nodes[0]->answerText = "Okay";
	nodes[0]->questionText = "What do you want?";

	nodes[1] = Node::create(3, 4, 5);
	nodes[1]->answerText = "To be happy.";
	nodes[1]->questionText = "What would make you happy right now?";

	nodes[2] = Node::create(67, -1, 47);
	nodes[2]->answerText = "I don't know.";
	nodes[2]->questionText = "If you don't know what you want from these sessions, I can't help you.";

	nodes[3] = Node::create(-1, 6, -1);
	nodes[3]->answerText = "Sitting at home, eating ice cream and watching TV.";
	nodes[3]->questionText = "Heh.";

	nodes[4] = Node::create(13, -1, 14);
	nodes[4]->answerText = "Being with my family.";
	nodes[4]->questionText = "That's really good. How's your mother doing?";

	nodes[5] = Node::create(20, 30, 39);
	nodes[5]->answerText = "Seeing my friends.";
	nodes[5]->questionText = "What do you like doing with your friends?";

	nodes[6] = Node::create(-1, 7, -1);
	nodes[6]->answerText = "...";
	nodes[6]->questionText = "Sorry I shouldn't laugh.";

	nodes[7] = Node::create(8, 9, 10);
	nodes[7]->answerText = "It's fine, can we keep going.";
	nodes[7]->questionText = "It's good though! Everyone has something to help them adjust.";

	nodes[8] = Node::create(11, -1, 12);
	nodes[8]->answerText = "I feel like I'm shutting everyone out.";
	nodes[8]->questionText = "It's understandable that you'd want your own space right now, but you will get through this.";

	nodes[9] = Node::create(11, -1, 12);
	nodes[9]->answerText = "I feel like I don't know where to go from here..";
	nodes[9]->questionText = "That's a perfectly normal reaction, but you will get through this.";

	nodes[10] = Node::create(11, -1, 12);
	nodes[10]->answerText = "I don't know if it helps me adjust or helps me escape.";
	nodes[10]->questionText = "Even if it's an escape, time is the greatest healer.";

	nodes[11] = Node::create(53, -1, 59);
	nodes[11]->answerText = "You're probably right.";
	nodes[11]->questionText = "You're making good progress you know.";

	nodes[12] = Node::create(53, -1, 59);
	nodes[12]->answerText = "I'm not sure I believe that.";
	nodes[12]->questionText = "You're making good progress you know.";

	nodes[13] = Node::create(15, 16, 17);
	nodes[13]->answerText = "She say's she's doing okay.";
	nodes[13]->questionText = "Of course, but it's cant be easy for her.";

	nodes[14] = Node::create(15, 16, 17);
	nodes[14]->answerText = "We haven't really talked yet.";
	nodes[14]->questionText = "You have to be there for her, you know that.";

	nodes[15] = Node::create(18, -1, 19);
	nodes[15]->answerText = "It's not easy for me either.";
	nodes[15]->questionText = "Well I'm glad you have her around to help you through this.";

	nodes[16] = Node::create(18, -1, 19);
	nodes[16]->answerText = "...I said she's fine.";
	nodes[16]->questionText = "Well I'm glad you two have each other.";

	nodes[17] = Node::create(18, -1, 19);
	nodes[17]->answerText = "Yeah, I can't image what she's going through right now.";
	nodes[17]->questionText = "I'm glad she has you.";

	nodes[18] = Node::create(53, -1, 59);
	nodes[18]->answerText = "Yeah, me too.";
	nodes[18]->questionText = "You're making good progress you know.";

	nodes[19] = Node::create(53, -1, 59);
	nodes[19]->answerText = "...";
	nodes[19]->questionText = "You're making good progress you know.";

	nodes[20] = Node::create(21, 22, 23);
	nodes[20]->answerText = "Lately, nothing";
	nodes[20]->questionText = "Do you want to see them?";

	nodes[21] = Node::create(24, 25, 26);
	nodes[21]->answerText = "I don't want their sympathy. I'm fine on my own.";
	nodes[21]->questionText = "You shouldn't push them away, all they want is to help you through this.";

	nodes[22] = Node::create(24, 25, 26);
	nodes[22]->answerText = "Yeah I do, but they don't understand what I'm going through.";
	nodes[22]->questionText = "They undetstand that you're upset. That might be enough.";

	nodes[23] = Node::create(24, 25, 26);
	nodes[23]->answerText = "They're always so busy...";
	nodes[23]->questionText = "If they knew you wanted to see them more, I'm sure they'd be by your side in an instant.";

	nodes[24] = Node::create(-1, 27, -1);
	nodes[24]->answerText = "Maybe.";
	nodes[24]->questionText = "I mean it. Let them distract you if you need something to occupy your mind.";

	nodes[25] = Node::create(-1, 28, -1);
	nodes[25]->answerText = "Whatever.";
	nodes[25]->questionText = "I know your friends mean a lot to you, don't ever forget that.";

	nodes[26] = Node::create(-1, 29, -1);
	nodes[26]->answerText = "You think so?";
	nodes[26]->questionText = "I know so";

	nodes[27] = Node::create(53, -1, 59);
	nodes[27]->answerText = "I'll try";
	nodes[27]->questionText = "You're making good progress you know.";

	nodes[28] = Node::create(53, -1, 59);
	nodes[28]->answerText = "I won't.";
	nodes[28]->questionText = "You're making good progress you know.";

	nodes[29] = Node::create(53, -1, 59);
	nodes[29]->answerText = "Thank you.";
	nodes[29]->questionText = "You're making good progress you know.";

	nodes[30] = Node::create(31, -1, 32);
	nodes[30]->answerText = "I love talking to them, I feel I can depend on them for anything.";
	nodes[30]->questionText = "It's good that you don't feel like you have to keep your feelings inside.";

	nodes[31] = Node::create(35, -1, 36);
	nodes[31]->answerText = "With this though, I don't know if I can rely on them.";
	nodes[31]->questionText = "Why do you think that?";

	nodes[32] = Node::create(33, -1, 34);
	nodes[32]->answerText = "They were with me at the funeral, and I've seen them every day since.";
	nodes[32]->questionText = "Do you feel like they're helping you through this?";

	nodes[33] = Node::create(35, -1, 36);
	nodes[33]->answerText = "No.";
	nodes[33]->questionText = "Why do you think that?";

	nodes[34] = Node::create(-1, 38, -1);
	nodes[34]->answerText = "Yes, I'd feel so much worse without them.";
	nodes[34]->questionText = "That's good! Amazing actually! You should be proud of yourself, and of your friends.";

	nodes[35] = Node::create(24, 25, 26);
	nodes[35]->answerText = "They don't know what it's like to be in my situation.";
	nodes[35]->questionText = "But they don't have to, they're your friends and they'll be there for your regardless.";

	nodes[36] = Node::create(-1, 37, -1);
	nodes[36]->answerText = "I don't know..";
	nodes[36]->questionText = "I'm sorry to hear that, I'm sure they're trying their hardest.";

	nodes[37] = Node::create(53, -1, 59);
	nodes[37]->answerText = "I just... I don't know who I want to keep around anymore around anymore.";
	nodes[37]->questionText = "You're making good progress you know.";

	nodes[38] = Node::create(53, -1, 59);
	nodes[38]->answerText = "Well thanks, though I don't feel like I deserve much praise.";
	nodes[38]->questionText = "You're making good progress you know.";

	nodes[39] = Node::create(40, 41, 42);
	nodes[39]->answerText = "Oh, we go out and get drunk every night.";
	nodes[39]->questionText = "I hope you're not using that as an alternative to grieving.";

	nodes[40] = Node::create(-1, 43, -1);
	nodes[40]->answerText = "I should probably take it easy, shouldn't I.";
	nodes[40]->questionText = "That wouldn't be a bad idea.";

	nodes[41] = Node::create(-1, 43, -1);
	nodes[41]->answerText = "So what if I am?.";
	nodes[41]->questionText = "Dealing with this is the only way to get past it. Ignoring it won't work forever.";

	nodes[42] = Node::create(-1, 43, -1);
	nodes[42]->answerText = "No, I just... I don't want to deal with this right now.";
	nodes[42]->questionText = "Dealing with this is the only way to get past it. Ignoring it won't work forever.";

	nodes[43] = Node::create(44, -1, 45);
	nodes[43]->answerText = "I don't know if I know a better way to deal with all this shit.";
	nodes[43]->questionText = "You're in therapy, that's a good start.";

	nodes[44] = Node::create(-1, 46, -1);
	nodes[44]->answerText = "I just want the pain to stop.";
	nodes[44]->questionText = "I know.";

	nodes[45] = Node::create(-1, 46, -1);
	nodes[45]->answerText = "I just want to feel something again.";
	nodes[45]->questionText = "I know.";

	nodes[46] = Node::create(53, -1, 59);
	nodes[46]->answerText = "I wish I could just skip to the part where I feel better and never have to come back here again.";
	nodes[46]->questionText = "You're making good progress you know.";

	nodes[47] = Node::create(-1, 48, -1);
	nodes[47]->answerText = "What I want is for this to be over.";
	nodes[47]->questionText = "Well I know this is what's best for you, your father would want this.";

	nodes[48] = Node::create(49, -1, 50);
	nodes[48]->answerText = "He would want me living my life instead of being in therapy.";
	nodes[48]->questionText = "He would want you to be happy.";

	nodes[49] = Node::create(-1, 51, -1);
	nodes[49]->answerText = "Maybe he would!";
	nodes[49]->questionText = "...";

	nodes[50] = Node::create(-1, 51, -1);
	nodes[50]->answerText = "You don't know him like I do!";
	nodes[50]->questionText = "...";

	nodes[51] = Node::create(-1, 52, -1);
	nodes[51]->answerText = "I'm sorry.";
	nodes[51]->questionText = "It's fine, this is why you're here. So we can work out your problems. Together.";

	nodes[52] = Node::create(44, -1, 45);
	nodes[52]->answerText = "I don't know if I can.";
	nodes[52]->questionText = "You're in therapy, that's a start.";

	nodes[53] = Node::create(-1, 54, -1);
	nodes[53]->answerText = "I don't feel like I am";
	nodes[53]->questionText = "I mean it, you are.";

	nodes[54] = Node::create(55, 56, 57);
	nodes[54]->answerText = "I feel like nothing we're talking about is helping.";
	nodes[54]->questionText = "Do you want me to stop?";

	nodes[55] = Node::create(-1, 58, -1);
	nodes[55]->answerText = "No.";
	nodes[55]->questionText = "Okay.";

	nodes[56] = Node::create(-1, 58, -1);
	nodes[56]->answerText = "Please don't.";
	nodes[56]->questionText = "It's okay, I won't.";

	nodes[57] = Node::create(-1, 58, -1);
	nodes[57]->answerText = "I just miss him.";
	nodes[57]->questionText = "I know you do.";

	nodes[58] = Node::create(0, -1, 65);
	nodes[58]->answerText = "...";
	nodes[58]->questionText = "Let's go back a bit, shall we?";

	nodes[59] = Node::create(-1, 60, -1);
	nodes[59]->answerText = "Yeah, right.";
	nodes[59]->questionText = "I mean it, you are.";

	nodes[60] = Node::create(61, 62, 63);
	nodes[60]->answerText = "Then thanks, it means a lot that you're doing this.";
	nodes[60]->questionText = "I mean, you are paying me.";

	nodes[61] = Node::create(-1, 64, -1);
	nodes[61]->answerText = "Ahahahahahaha.";
	nodes[61]->questionText = "It's good to see you smile";

	nodes[62] = Node::create(-1, 64, -1);
	nodes[62]->answerText = "Hahahaha.";
	nodes[62]->questionText = "Let's go back a bit, shall we?";

	nodes[63] = Node::create(-1, 64, -1);
	nodes[63]->answerText = "Heh.";
	nodes[63]->questionText = "But I'm here for you if you ever need anything.";

	nodes[64] = Node::create(0, -1, 65);
	nodes[64]->answerText = "I appreciate that";
	nodes[64]->questionText = "Let's go back a bit, shall we?";

	nodes[65] = Node::create(-1, 66, -1);
	nodes[65]->answerText = "Actually, I think I'm gonna call it there. Thanks for today.";
	nodes[65]->questionText = "...... Your Dad was a wonderful man.";

	nodes[66] = Node::create(-1, -1, -1);
	nodes[66]->answerText = "I know";
	nodes[66]->questionText = "The End";

	// I fucked up
	nodes[67] = Node::create(3, 4, 5);
	nodes[67]->answerText = "I want to get better.";
	nodes[67]->questionText = "Okay, what usually makes you feel good?";
}

void Game::Events()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			shouldQuit = true;
	}
}

void Game::Update()
{
	player.Update();
}

void Game::Draw()
{
	window.clear(sf::Color::White);
	window.draw(player);
	window.display();
}
