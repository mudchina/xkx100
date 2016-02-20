//miaorenbuluo.c

inherit ROOM;

void create()
{
	set("short", "苗人部落");
	set("long", @TEXT
你眼前突然一亮，原来是走进了一个苗人部落。苗人们围坐在火堆
边，面色虔诚，好象在作某种祭神仪式。几个巫士挥舞着木镗，口中念
念有词。突然，他们好象发现了你。
TEXT );
	set("outdoors", "mingjiao");
 	set("exits",([
		"north" : __DIR__"westroad2",
	]));
	set("objects",([
		"/d/mingjiao/npc/miaozuwushi":4,	
	]));
	set("coor/x", -31000);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}