// /kaifeng/tieta.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "开封铁塔");
	set("long", @LONG
塔高五十五米，八角十三层。当年此地为宋开宝寺，故又名『开宝
寺塔』，塔身为褐色琉璃砖砌成混私铁铸，民间俗称其为铁塔。塔身修
长，气势雄伟，砖面饰以飞天、佛像、乐伎等数十种图案，栩栩如生。
LONG);
	set("outdoors", "kaifeng");
	set("exits", ([
		"west" : __DIR__"jieyin",
		"east" : __DIR__"eroad3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
