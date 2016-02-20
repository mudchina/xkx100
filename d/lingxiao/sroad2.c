// Room: /d/lingxiao/sroad2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG
这时雪更大些了，使得地上盖上了厚厚的一层。正值朝阳初出，从
山顶倒挂下来的冰川，由于太阳光的折射和发射，整个冰层都变成浅蓝
色的透明体，那些末曾凝结的雪花，在阳光底下，泛出霞辉丽彩，奇妙
得难以形容。山路也渐渐不平坦起来，走一步跌三步，联想到古诗所说
：“去时雪满天山路”，也不过如此吧。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
	    "southdown" : __DIR__"sroad1",
	    "northup"   : __DIR__"sroad3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8990);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}

