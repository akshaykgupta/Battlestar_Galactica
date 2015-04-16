#ifndef KEY_TO_STRING
#define KEY_TO_STRING

//Utility functions.

std::string toString(sf::Keyboard::Key key) {
	string ans;
	switch(key) {
        case (A		        ) : { ans = "A"; break; }
        case (B	            ) : { ans = "B"; break; }
        case (C	            ) : { ans = "C"; break; }
        case (D	            ) : { ans = "D"; break; }
        case (E	            ) : { ans = "E"; break; }
        case (F	            ) : { ans = "F"; break; }
        case (G	            ) : { ans = "G"; break; }
        case (H	            ) : { ans = "H"; break; }
        case (I	            ) : { ans = "I"; break; }
        case (J	            ) : { ans = "J"; break; }
        case (K	            ) : { ans = "K"; break; }
        case (L	            ) : { ans = "L"; break; }
        case (M	            ) : { ans = "M"; break; }
        case (N	            ) : { ans = "N"; break; }
        case (O	            ) : { ans = "O"; break; }
        case (P	            ) : { ans = "P"; break; }
        case (Q	            ) : { ans = "Q"; break; }
        case (R	            ) : { ans = "R"; break; }
        case (S	            ) : { ans = "S"; break; }
        case (T	            ) : { ans = "T"; break; }
        case (U	            ) : { ans = "U"; break; }
        case (V	            ) : { ans = "V"; break; }
        case (W	            ) : { ans = "W"; break; }
        case (X	            ) : { ans = "X"; break; }
        case (Y	            ) : { ans = "Y"; break; }
        case (Z	            ) : { ans = "Z"; break; }
        case (Num0	         ) : { ans = "Num0"; break; }
        case (Num1	         ) : { ans = "Num1"; break; }
        case (Num2	         ) : { ans = "Num2"; break; }
        case (Num3	         ) : { ans = "Num3"; break; }
        case (Num4	         ) : { ans = "Num4"; break; }
        case (Num5	         ) : { ans = "Num5"; break; }
        case (Num6	         ) : { ans = "Num6"; break; }
        case (Num7	         ) : { ans = "Num7"; break; }
        case (Num8	         ) : { ans = "Num8"; break; }
        case (Num9	         ) : { ans = "Num9"; break; }
        case (Escape      	) : { ans = "Esc"; break; }
        case (LControl    	) : { ans = "LCtrl"; break; }
        case (LShift      	) : { ans = "LShft"; break; }
        case (LAlt        	) : { ans = "LAlt"; break; }
        case (LSystem     	) : { ans = "LSys"; break; }
        case (RControl    	) : { ans = "RCtrl"; break; }
        case (RShift      ) : { ans = "RShft"; break; }
        case (RAlt        ) : { ans = "RAlt"; break; }
        case (RSystem     ) : { ans = "RSys"; break; }
        case (Menu        ): { ans = "Menu"; break; }
        case (LBracket     ) : { ans = "LBracket"; break; }
        case (RBracket     ) : { ans = "RBracket"; break; }
        case (SemiColon    ) : { ans = ";"; break; }
        case (Comma        ) : { ans = ","; break; }
        case (Period       ) : { ans = "."; break; }
        case (Quote        ) : { ans = "\""; break; }
        case (Slash        ) : { ans = "\\"; break; }
        case (BackSlash    ) : { ans = "/"; break; }
        case (Tilde        ) : { ans = "~"; break; }
        case (Equal        ) : { ans = "="; break; }
        case (Dash         ) : { ans = "-"; break; }
        case (Space   		) : { ans = " "; break; }
        case (Return  		) : { ans = "return"; break; }
        case (BackSpace   		) : { ans = "backspace"; break; }
        case (Tab         		) : { ans = "tab"; break; }
        case (PageUp    		) : { ans = "pageup"; break; }
        case (PageDown    		) : { ans = "pagedown"; break; }
        case (End   		) : { ans = "end"; break; }
        case (Home  		) : { ans = "home"; break; }
        case (Insert   		) : { ans = "Insert"; break; }
        case (Delete   		) : { ans = "Delete"; break; }
        case (Add          ) : { ans = "Add"; break; }
        case (Subtract     ) : { ans = "Subtract"; break; }
        case (Multiply     ) : { ans = "Multiply"; break; }
        case (Divide       ) : { ans = "Divide"; break; }
        case (Left         ) : { ans = "Left"; break; }
        case (Right        ) : { ans = "Right"; break; }
        case (Up         ) : { ans = "Up"; break; }
        case (Down         ) : { ans = "Down"; break; }
        case (Numpad0      ) : { ans = "Numpad0"; break; }
        case (Numpad1      ) : { ans = "Numpad1"; break; }
        case (Numpad2      ) : { ans = "Numpad2"; break; }
        case (Numpad3      ) : { ans = "Numpad3"; break; }
        case (Numpad4      ) : { ans = "Numpad4"; break; }
        case (Numpad5      ) : { ans = "Numpad5"; break; }
        case (Numpad6      ) : { ans = "Numpad6"; break; }
        case (Numpad7      ) : { ans = "Numpad7"; break; }
        case (Numpad8      ) : { ans = "Numpad8"; break; }
        case (Numpad9      ) : { ans = "Numpad9"; break; }
        case (F1          ) : { ans = "F1"; break; }
        case (F2          ) : { ans = "F2"; break; }
        case (F3          ) : { ans = "F3"; break; }
        case (F4          ) : { ans = "F4"; break; }
        case (F5          ) : { ans = "F5"; break; }
        case (F6          ) : { ans = "F6"; break; }
        case (F7          ) : { ans = "F7"; break; }
        case (F8          ) : { ans = "F8"; break; }
        case (F9          ) : { ans = "F9"; break; }
        case (F10          ) : { ans = "F10"; break; }
        case (F11          ) : { ans = "F11"; break; }
        case (F12          ) : { ans = "F12"; break; }
        case (F13          ) : { ans = "F13"; break; }
        case (F14          ) : { ans = "F14"; break; }
        case (F15         ) : { ans = "F15"; break; }
        case (Pause        ) : { ans = "Pause"; break; }
		default : { ans = "not valid";break;}
	}
	return ans;
}

std::string toString(KeyboardInput key) {
	string ans;
	switch(key) {
		case (ACCELERATE) : { ans = "accelerate"; break; }
		case (DECELERATE) : { ans = "decelerate"; break; }
		case (STRAFE_LEFT) : { ans = "strafe-left"; break; }
		case (STRAFE_RIGHT) : { ans = "strafe-right"; break; }
		case (ASCEND) : { ans = "ascend"; break; }
		case (DESCEND) : { ans = "descend"; break; }
		case (PITCH_UP) : { ans = "pitch-up" ; break; }
		case (PITCH_DOWN) : { ans = "pitch-down" ; break; }
		case (YAW_LEFT) : { ans = "yaw-left" ; break; }
		case (YAW_RIGHT) : { ans = "yaw-right" ; break; }
		case (ROLL_LEFT) : { ans = "right-left" ; break; }
		case (ROLL_RIGHT) : { ans = "roll-right" ; break; }
		case (TOGGLE_FULLSCREEN) : { ans = "toggle-fscrn" ; break; }
		case (TOGGLE_CAM) : { ans = "toggle-cam" ; break; }
		case (FIRE_WEAPON) : { ans = "shoot" ; break; }
		case (TOGGLE_WEAPONLE) : { ans = "toggle-weapon" ; break; }
		case (USE_ABILITY) : { ans = "use-ability" ; break; }
		case (ESCAPE) : { ans = "escape" ; break; }
		case (START_CHAT) : { ans = "start-chat" ; break; }
		case (ESCAPE_CHAT) : { ans = "escape-chat" ; break; }
		case (SEND_CHAT) : { ans = "send-chat" ; break; }
		default : { ans = "not valid";break;}
	}
	return ans;	
}
sf::Keyboard::Key fromString(std::string str) {
	sf::Keyboard::Key ans=Unknown;
	switch(str) {
		case("A") : { ans=A; break; }
		case("B") : { ans=B; break; }
		case("C") : { ans=C; break; }
		case("D") : { ans=D; break; }
		case("E") : { ans=E; break; }
		case("F") : { ans=F; break; }
		case("G") : { ans=G; break; }
		case("H") : { ans=H; break; }
		case("I") : { ans=I; break; }
		case("J") : { ans=J; break; }
		case("K") : { ans=K; break; }
		case("L") : { ans=L; break; }
		case("M") : { ans=M; break; }
		case("N") : { ans=N; break; }
		case("O") : { ans=O; break; }
		case("P") : { ans=P; break; }
		case("Q") : { ans=Q; break; }
		case("R") : { ans=R; break; }
		case("S") : { ans=S; break; }
		case("T") : { ans=T; break; }
		case("U") : { ans=U; break; }
		case("V") : { ans=V; break; }
		case("W") : { ans=W; break; }
		case("X") : { ans=X; break; }
		case("Y") : { ans=Y; break; }
		case("Z") : { ans=Z; break; }
		case("Num0") : { ans=Num0; break; }
		case("Num1") : { ans=Num1; break; }
		case("Num2") : { ans=Num2; break; }
		case("Num3") : { ans=Num3; break; }
		case("Num4") : { ans=Num4; break; }
		case("Num5") : { ans=Num5; break; }
		case("Num6") : { ans=Num6; break; }
		case("Num7") : { ans=Num7; break; }
		case("Num8") : { ans=Num8; break; }
		case("Num9") : { ans=Num9; break; }
		case("Esc") : { ans=Esc; break; }
		case("LCtrl") : { ans=LControl; break; }
		case("LShft") : { ans=LShift; break; }
		case("LAlt") : { ans=LAlt; break; }
		case("LSys") : { ans=LSystem; break; }
		case("RCtrl") : { ans=RControl; break; }
		case("RShft") : { ans=RShift; break; }
		case("RAlt") : { ans=RAlt; break; }
		case("RSys") : { ans=RSystem; break; }
		case("Menu") : { ans=Menu; break; }
		case("LBracket") : { ans=LBracket; break; }
		case("RBracket") : { ans=RBracket; break; }
		case("pageup") : { ans=PageUp; break; }
		case("pagedown") : { ans=PageDown; break; }
		case("Left") : { ans=Left; break; }
		case("Right") : { ans=Right; break; }
		case("Up") : { ans=Up; break; }
		case("Down") : { ans=Down; break; }
		case("Numpad0") : { ans=Numpad0; break; }
		case("Numpad1") : { ans=Numpad1; break; }
		case("Numpad2") : { ans=Numpad2; break; }
		case("Numpad3") : { ans=Numpad3; break; }
		case("Numpad4") : { ans=Numpad4; break; }
		case("Numpad5") : { ans=Numpad5; break; }
		case("Numpad6") : { ans=Numpad6; break; }
		case("Numpad7") : { ans=Numpad7; break; }
		case("Numpad8") : { ans=Numpad8; break; }
		case("Numpad9") : { ans=Numpad9; break; }
		case("F1") : { ans=F1; break; }
		case("F2") : { ans=F2; break; }
		case("F3") : { ans=F3; break; }
		case("F4") : { ans=F4; break; }
		case("F5") : { ans=F5; break; }
		case("F6") : { ans=F6; break; }
		case("F7") : { ans=F7; break; }
		case("F8") : { ans=F8; break; }
		case("F9") : { ans=F9; break; }
		case("F10") : { ans=F10; break; }
		case("F11") : { ans=F11; break; }
		case("F12") : { ans=F12; break; }
		case("F13") : { ans=F13; break; }
		case("F14") : { ans=F14; break; }
		case("F15") : { ans=F15; break; }
		default:{ans=Unknown;break;}
	}
	return ans;
}

#endif