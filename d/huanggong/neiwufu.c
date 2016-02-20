// Room: /d/huanggong/neiwufu.c

inherit ROOM;

void create()
{
	set("short", "内务府");
	set("long", @LONG
内务府专司宫内。下置七司：广储司、都虞司、掌仪司、庆丰司、
会计司、营造司、慎刑司，和三院：上驷院、武备院、奉宸院，各司其
职。内务府在乾清门内设敬事房，专门管理宫内太监。
LONG
	);
	set("exits", ([
		"south"     : __DIR__"wuying",
	]));
	set("no_clean_up", 0);
	set("coor/x", -220);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}