# Betelgeuse (alpha) integration/staging tree
Betelgeuse project is another effort to expand the use of smart properties, tokens and smart contracts on top of public blockchains (in this case Bitcoin Gold). Is based on OmniLayer protocol. Note: It's beggining stage.


# Omni Layer

The Omni Layer is a communications protocol that uses the Bitcoin block chain to enable features such as smart contracts, user currencies and decentralized peer-to-peer exchanges. A common analogy that is used to describe the relation of the Omni Layer to Bitcoin is that of HTTP to TCP/IP: HTTP, like the Omni Layer, is the application layer to the more fundamental transport and internet layer of TCP/IP, like Bitcoin.
http://www.omnilayer.org


# Bitcoin Gold

[![Build Status](https://travis-ci.org/BTCGPU/BTCGPU.svg?branch=master)](https://travis-ci.org/BTCGPU/BTCGPU)

Bitcoin Gold (codename BTCGPU) began as a fork of Bitcoin after block height 491406 on Tue, 24 Oct 2017 01:17:35 GMT and began being mined as a separate chain at block height 491407 on Sun, 12 Nov 2017 13:34:01 GMT.

The primary goal is to maintain a variant of Bitcoin that is more decentralized by using an ASIC-resistant Proof of Work algorithm, removing barriers to entry for new miners around the world and reducing the concentration of power in the hands of massive-scale mining operations.

Bitcoin Gold preserves and implements Bitcoin features such as SegWit, which enables advanced scaling technologies like Lightning Network. Significant differences at launch time included:

- ASIC-resistant GPU-minable PoW algorithm (Equihash)
- Per-block difficulty adjustment algorithm
- Replay protection (SIGHASH_FORK_ID)
- Unique wallet addresses (prefixes of G and A)

Although BTG was bootstrapped on 12 Nov to create an entirely new network, it contains the entire Bitcoin blockchain until block 491406. As a result, Bitcoin Gold became a full fork with all Bitcoin transaction history since 2009. Any Bitcoin wallet address which held Bitcoin in BTC block 491406 before the fork held an equal number of Bitcoin Gold in BTG block 491407 after the fork.

## Releases

This is the staging tree of Bitcoin Gold. For release version, please switch to [0.15 branch](https://github.com/BTCGPU/BTCGPU/tree/0.15) or [release page](https://github.com/BTCGPU/BTCGPU/releases).

To compile from source, please check the build documentations under [doc](https://github.com/BTCGPU/BTCGPU/tree/master/doc).

## Responsible Disclosure

At the Bitcoin Gold, we consider the security of our systems a top priority. But no matter how much effort we put into system security, there can still be vulnerabilities present.

If you discover a vulnerability, we would like to know about it so we can take steps to address it as quickly as possible. We would like to ask you to help us better protect our users and our systems.

Please check our [Responsible Disclosure](https://bitcoingold.org/responsible-disclosure/) page for more details.

## Links

* Website: https://bitcoingold.org
* Tech Spec: https://github.com/BTCGPU/BTCGPU/wiki/Technical-Spec
* Twitter: https://twitter.com/bitcoingold
* Facebook: https://www.facebook.com/bitcoingoldofficial/
* Forum: https://forum.bitcoingold.org
* Discord: [invitation](https://discord.gg/HmVUU6S)
* Telegram (Global): https://t.me/BitcoinGoldHQ
