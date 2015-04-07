#ifndef WEAPON_HPP
#define WEAPON_HPP

enum WEAPON_TYPE {
	WEAK_LASER = 1,
	MEDIUM_LASER = 2,
	STRONG_LASER = 3,
	CANNON = 4,
	HEAT_MISSILE = 5,
	FORCE = 6
};

struct Weapon {

	WEAPON_TYPE type;
	float strength;
	float r,g,b;
	double regen_rate;
	int max_ammo,ammo;
	bool active;
	int time_left;
	SpaceObject* fighter;
	BulletWorld* world;
	btVector3 last_from, last_to;
	Weapon(WEAPON_TYPE t , btVector3& color) {
		type = t;
		switch (t) {
			case WEAK_LASER   : {
				ammo = max_ammo = 10000; break;
			}
			case MEDIUM_LASER : {
				ammo = max_ammo = 5000; break;
			}
			case STRONG_LASER : {
				ammo = max_ammo = 1000; break;
			}
			default : {
				break;
			}
		}
		r = color.getX();
		g = color.getY();
		b = color.getZ();
	}
	~Weapon() {

	}
	void fireProjectile(btVector3& from, btVector3& to) {
		last_from = from;
		last_to  = to;
		time_left = 10;
		switch (type) {
			case WEAK_LASER   : {
				if (ammo > 100) {
					drawProjectile(from,to);
					ammo -= 100; 
					break;
				}
			}
			case MEDIUM_LASER : {
				if (ammo > 100) {
					drawProjectile(from,to);
					ammo -= 100; 
					break;
				}
			}
			case STRONG_LASER : {
				if (ammo > 100) {
					drawProjectile(from,to);
					ammo -= 100; 
					break;
				}
			}
			default : {
				break;
			}
		}
	}

	void drawProjectile(btVector3& from, btVector3& to) {
		if ( time_left == 0 ) {
			return;
		} 
		time_left--;
		glColor3f(r,g,b);
		
		glLineWidth(strength);
		glBegin(GL_LINES);
			glVertex3f(last_from.getX(), last_from.getY(), last_from.getZ());
			glVertex3f(last_to.getX(), last_to.getY(), last_to.getZ());
		glEnd();
	}

	void update() {
		if (active) {
			ammo += (regen_rate*max_ammo);
			if (ammo>max_ammo) { ammo = max_ammo ; }
		}
		drawProjectile(last_from , last_to);
	}
};
#endif