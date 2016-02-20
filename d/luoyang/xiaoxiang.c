//  Room:  /d/luoyang/xiaoxiang.c

inherit  ROOM;

void  create  ()
{
	set("short",  "中通巷");
	set("long",  @LONG
你刚踏进巷子，便听得琴韵丁冬，有人正在抚琴，小巷中一片清凉
宁静，和外面的洛阳城宛然是两个世界。窄窄的巷子尽头，好大一片绿
竹丛，迎风摇曳，雅致天然。你不禁感叹道：“这里的居士好会享清福
啊！”
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"      :  __DIR__"tongtuo",
		"north"     :  __DIR__"lvzhulin",
		"southwest" :  __DIR__"xiaojie2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "luoyang");
	set("coor/x", -380);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
