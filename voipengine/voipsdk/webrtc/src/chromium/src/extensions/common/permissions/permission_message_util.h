// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef EXTENSIONS_COMMON_PERMISSIONS_PERMISSION_MESSAGE_UTIL_H_
#define EXTENSIONS_COMMON_PERMISSIONS_PERMISSION_MESSAGE_UTIL_H_

#include <set>
#include <string>

namespace extensions {
class PermissionMessage;
class PermissionSet;
class URLPatternSet;
}

namespace permission_message_util {

enum PermissionMessageProperties { kReadOnly, kReadWrite };

// Creates the corresponding permission message for a list of hosts.
// The messages change depending on how many hosts are present, and whether
// |read_only| is true.
extensions::PermissionMessage CreateFromHostList(
    const std::set<std::string>& hosts,
    PermissionMessageProperties);

std::set<std::string> GetDistinctHosts(
    const extensions::URLPatternSet& host_patterns,
    bool include_rcd,
    bool exclude_file_scheme);

}  // namespace permission_message_util

#endif  // EXTENSIONS_COMMON_PERMISSIONS_PERMISSION_MESSAGE_UTIL_H_