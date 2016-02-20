// Room: /d/nanshaolin/sengshe6.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "西僧舍");
	set("long", @LONG
这里是僧众们饮食起居的地方。靠墙一溜摆着几张木床，床上铺的
是篾席。床头叠着床薄被，冬天想必很冷，僧侣们全靠扎实的内功根基
御寒。地上整齐的放着几个蒲团和木鱼。
LONG );
	set("sleep_room",1);
        set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"sengshe4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}



