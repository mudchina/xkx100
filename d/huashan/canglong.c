// canglong.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "苍龙岭");
	set("long", @LONG
华山五峰中最惊险的是北峰，北峰之上最陡峭的则是苍龙岭。此岭
高约百米，宽仅一米，而登山之路则在其山脊之上，两侧脊坡光滑挺拔，
其下悬崖深邃，云涛隐伏，岭体蜿蜒逶迤，体青背黑，如苍龙腾空，故
有是名。岭侧有一石碑(shibei)。
	从这里往东是下山的路，再往南是上其它四峰的路，西面是华山极
险处之一，叫做“舍身崖”。
LONG );
	set("exits", ([ /* sizeof() == 3 */
		"westup"   : __DIR__"sheshen",
		"northup"  : __DIR__"yuntai",
		"eastdown" : __DIR__"shangtianti",
	]));
	set("item_desc", ([
		"shibei" :
"石碑刻着几个大字：「韩退之投书处」，据说当年韩愈爬上此岭之后，\n
再也不敢下来，自以为要死在山上，就在山上写信投下来，和家人诀别。\n
后来还是华阴县的县官派人上山拿绳子把他捆着吊下来的。\n"
]) ) ;
	set("objects", ([
		__DIR__"npc/liang-fa" : 1,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -880);
	set("coor/y", 210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
 
