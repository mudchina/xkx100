// Room: /yangzhou/hepuxunfeng.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","荷浦熏风");
	set("long",@LONG
荷浦熏风位于长堤春柳东岸。为清乾隆布政使衔江春所筑家园，故
称“江园”。乾隆高宗南巡时赐名净香园。园内有清华堂、青雨廊、杏
花春雨之堂，又有怡性堂、翠玲珑馆及涵虚阁。涵虚阁外，构小亭置四
屏风，嵌“荷浦熏风”四字。此处前湖后浦，分种红、白荷花。夏日临
湖小憩，熏风拂面，令人呼吸清凉，热念顿消。
    江园内飞甍反宇，五色填漆，一片金碧，照耀湖山，每当夕阳西下，
殿角铃声与画船箫鼓辄相应答。
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"north" : __DIR__"siqiaoyanyu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 2);
	set("coor/y", 39);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}