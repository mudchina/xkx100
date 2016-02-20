// Room: /d/wuxi/chongansi.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "崇安寺");
	set("long", @LONG
这座江南古刹兴修于东晋初年，历经兴衰，香火日渐旺盛。每逢六
月十九，寺中还召以为集，四方商贾咸集，辇物来市，踵趾相接；再逢
元宵节，这里还日放爆竹，夜燃烟火，十分热闹。不少得道高僧都相继
来此主持，九方也在此形成共约，庙内不得打架斗殴。向东是大殿。
LONG );
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	set("exits", ([
		"enter"  : __DIR__"chongandadian",
		"west"   : __DIR__"northroad1",
	]));
	set("coor/x", 380);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}