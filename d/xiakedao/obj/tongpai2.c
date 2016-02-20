// /d/xiakedao/obj/tongpai1.c
//edit by noz
// Modified by Zeratul Jan 11 2001 铜牌退出时不丢，不能给人

#include <ansi.h>
inherit ITEM;

void create()
{
  	set_name( "罚恶铜牌",({"e pai"}));
  	set_weight(100);

  	if( clonep() )
        	set_default_object(__FILE__);

  	set("unit", "块");
  	set("long", "这是一块闪闪发光的白铜片子，约有巴掌大小，牌子正面刻着一张狰狞的煞神凶脸，十分诡异。\n" );
	set("no_put",1);
	set("no_get",1);
	set("no_drop",1);
	set("no_beg",1);
	set("no_steal",1);

  	setup();
}

string query_autoload() 
{ 
	if ( query("own") != this_player()->query("id") )
		return 0;
	if ( time() > this_player()->query( "xkd/time" ) )
		return 0;
	return query("own"); 
}

void autoload(string param)
{
	string owner;

	if ( !objectp( this_object() ) )
		return;
	if ( time() > this_player()->query( "xkd/time" ) )
	{
		destruct( this_object() );
		return;
	}
	if( sscanf(param, "%s", owner)==1 )
		set( "own", owner );
}

int init()
{
	string long_msg = this_object()->query( "long" );
	
  	if ( this_player()->query( "xkd/time" ) )
  		long_msg += HIC"牌子背面刻得有字：侠客岛于" + CHINESE_D->chinese_date( ( (this_player()->query( "xkd/time" ) - 950000000 ) * 60 ) ) + "前恭候大驾。\n"NOR;
  	this_object()->set( "long", long_msg );
	return 1;
}
