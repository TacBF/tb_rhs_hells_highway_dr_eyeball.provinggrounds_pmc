#include "tb_defines.hpp"

zoneList[] =
{
//ID TEAM          SPAWNTYPE      LINK         SYNC   PROFILE   DEPEND     DEPQTY  ZONE_DESC
{ 0, 0           , 0         ,    {}         , {}    , 1      , {}        , 0      },

{ 1, TEAM_BLUE    , SPAWN_XRAY,     {}          , {}    , 1      , {}        , 0    , "UA Main Base" },
{ 2, TEAM_RED   , SPAWN_XRAY,       {3}     , {}    , 1      , {}        , 0    , "Insurgents Main base" },



{ 3, TEAM_BLUE    , SPAWN_NEVER,    {4}     , {} , 1      , {}        , 0    , "%1" },
{ 4, TEAM_BLUE    , SPAWN_NEVER,    {5}     , {} , 1      , {}        , 0    , "%1" },
{ 5, TEAM_BLUE    , SPAWN_NEVER,    {6}     , {} , 1      , {}        , 0    , "%1" },
{ 6, TEAM_BLUE    , SPAWN_NEVER,    {1}     , {} , 1      , {}        , 0    , "%1" }





};
