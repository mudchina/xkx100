//gebitan1.c

inherit ROOM;

void create()
{
	set("short", "戈壁滩");
	set("long", @LONG
终于穿出了密林，眼前是一望无际的戈壁滩，没有路标，也没有一
个行人，天显得很高，远山披雪，苍鹰翱翔，好一派不同于中土的异域
风光。不远处，几只白骨散落地上，似乎是牦牛的尸骨。走在这茫茫戈
壁之上，你似乎迷路了。
LONG );
	set("outdoors", "mingjiao");
 	set("exits",([
		"east" : __DIR__"westroad2",
		"west" : __DIR__"gebitan2",	
		"north" : __DIR__"gebitan1",
		"south" : __DIR__"gebitan1",  				
	]));
	set("objects",([
		__DIR__"obj/shigu":3,	
	]));
	set("coor/x", -40000);
	set("coor/y", 800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}